/*
  Hex Memory Dumper

  Note: Parts of this memory dumper is specific to the Teensy 4.x boards

  This example code is in the public domain.
*/



#include <MemoryHexDump.h>

char var1[] = "variable one";
int var3 = 0x7FFA;
uint8_t buffer[256] = "Start of buffer";


void setup() {
  int var4 = 0x6F55;
  char var2[] = "variable two";
	while (!Serial && millis() < 5000) ;
	Serial.begin(115200);

	buffer[248] = 'E';
	buffer[249] = 'n';
	buffer[250] = 'd';
	buffer[252] = '!';
	buffer[253] = '!';
	buffer[254] = '.';

  MemoryHexDump(Serial, var1, 13, false, "\n*** var1 ***\n");
  MemoryHexDump(Serial, var2, 13, false, "\n*** var2 ***\n");
  MemoryHexDump(Serial, &var3, 2, false, "\n*** var3 ***\n");
  MemoryHexDump(Serial, &var4, 2, false, "\n*** var4 ***\n");
	MemoryHexDump(Serial, buffer, sizeof(buffer), false, "\n*** Buffer  dups not removed ***\n");
  
	//MemoryHexDump(Serial, buffer, sizeof(buffer), true, "\n*** Buffer dups removed ***\n");
	
	MemoryHexDump(Serial, (void*)0x020000000, 0x8ff-0x20, false, "\n*** DTCM Duplicates not removed ***\n");
	
  /*
  MemoryHexDump(Serial, (void*)0x020000000, 1024, true, "\n*** DTCM Duplicates removed ***\n");

	Serial.println("\n\nOCRAM2");
	Serial.println("*** Duplicates not removed ***");
	MemoryHexDump(Serial, (void*)0x020200000, 1024, false);
	Serial.println("*** Duplicates removed ***");
	MemoryHexDump(Serial, (void*)0x020200000, 1024, true);  */

}

void loop() {

}