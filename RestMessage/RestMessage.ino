#include <HT1632.h>
#include <font_8x4.h>
#include <images.h>
#include <YunServer.h>
#include <YunClient.h>
#include <Bridge.h>

int i = 0;
int wd;
byte disp [] = "Hello, how are you?";


YunServer server;
String msg;
String oldMsg = ""; 
 

void setup () {
  
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();  
  
  
  HT1632.setCLK(4);
   HT1632.begin(5, 6, 7);
  
  wd = HT1632.getTextWidth(disp, FONT_8X4_END, FONT_8X4_HEIGHT);
}

void loop () {
  
   //*********Read new message from the client**************
  YunClient client = server.accept(); //check new clients
   
  if(client) {
    String command = client.readStringUntil('/');  //read the incoming data 
    if (command == "msg") {      
       msg = client.readStringUntil('/');             // read the incoming data
    }
    client.stop();   
      msg.toCharArray((char*)disp,10); 
  }  
  
  

  
//  HT1632.drawTarget(BUFFER_BOARD(1));
  HT1632.clear();
  HT1632.drawText(disp, 0, 0, FONT_8X4, FONT_8X4_END, FONT_8X4_HEIGHT);
  HT1632.render();
  

  
  delay(100);
}
