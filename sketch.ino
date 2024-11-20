#include <WiFi.h>
#include <PubSubClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <LiquidCrystal_I2C.h>

#define SSID        "Wokwi-GUEST"
#define PASS        ""
#define MQTTSERVER  "test.mosquitto.org"
#define PORT        1883

#define TOPIC_SUBSCRIBE "esp32/adc/read"
#define TOPIC_PUBLISH "esp32_44565264598"

#define COLUNAS 20
#define LINHAS 4

char clientId[50];
char ad_array[5];

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long int time_ms;
unsigned int valor_ad;

bool flag_inicializacao = 0;

String atual, anterior = "";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "a.st1.ntp.br", -10800, 60000);

LiquidCrystal_I2C lcd(0x27, COLUNAS, LINHAS);

void setup()
{
  Serial.begin(115200);
  randomSeed(analogRead(0));
  
  lcd.init();
  lcd.backlight();

  delay(10);

  Serial.print("Se conectando a: ");
  Serial.println(SSID);

  WiFi.begin(SSID, PASS);
  
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");

    delay(500);
        lcd.setCursor(0, 0);
        if(flag_inicializacao)
        {
            lcd.print("Conectando...");
        }
        else
        {
            lcd.print("             ");
        }

        Serial.print(".");

        flag_inicializacao = !flag_inicializacao;
  }

  WiFi.mode(WIFI_STA);

  Serial.println("");
  Serial.println("Conexão Wi-Fi realizada");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  Serial.println("\nConectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Conectado!");
  lcd.setCursor(0, 1);
  lcd.print("IP: ");
  lcd.print(WiFi.localIP());

  timeClient.begin();

  client.setServer(MQTTSERVER, PORT);
  client.setCallback(callback);
}

void mqttReconnect()
{
  while(!client.connected())
  {
    Serial.print("Tentando conexão MQTT... ");
    
    long r = random(1);
    sprintf(clientId, "clientId-%ld", r);

    if(client.connect(clientId))
    {
      Serial.print(clientId);       
      Serial.println(" conectado"); 
    
      client.subscribe(TOPIC_SUBSCRIBE); 
    }
    else
    {
      Serial.print("falhou, rc="); 
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5 segundos");
    
      delay(5000);
    }
  }
}

void callback(char* topic, byte* message, unsigned int length)
{
  Serial.print("Mensagem recebida no tópico: ");
    
  Serial.print(topic);
  Serial.print(". Mensagem: "); 
  
  String stMessage;

  for(int i = 0; i < length; i++)
  {
    Serial.print((char)message[i]);
    stMessage += (char)message[i];
  }
}

void loop()
{
  if(!client.connected())
  {
    mqttReconnect();
  }

  client.loop();

  if(millis() - time_ms >= 500) 
   {
     time_ms = millis();
     valor_ad = analogRead(39); 
     sprintf(ad_array, "%04d", valor_ad);
     Serial.print("Gasto de Energia: ");
     Serial.println(ad_array);
     lcd.setCursor(3, 3);
     lcd.print(valor_ad);       
     client.publish(TOPIC_PUBLISH, ad_array);
   }
  
    if(millis() - time_ms >= 1000) 
    {
        time_ms = millis();
        timeClient.update(); 
        atual = timeClient.getFormattedTime();
    }

    if(atual != anterior) 
    {
        anterior = atual;
        Serial.println(atual);  
        lcd.setCursor(0, 3);
        lcd.print(valor_ad);       
    }
}
