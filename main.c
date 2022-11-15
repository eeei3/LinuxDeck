#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <libusb-1.0/libusb.h>
#include <hidapi/hidapi.h>
#define IMAGE_REPORT_LENGTH 8191

hid_device *streamdeck;
int res;
int i;
wchar_t wstr[255];
unsigned char buf[256];
int wait = 1;
char key_pressed[36];

int streamdeck_server()
{
	res = 0;

	while (wait == 1) {
		res = hid_read(streamdeck, buf, sizeof(buf));
		if (res < 0)
		{
			return -1;
		}
		else if (res != 0)
		{
			for (int x = 0; x < res; x++)
				strcat((unsigned int) buf[i], key_pressed);
		}
	}


	return 0;

}

int main()
{
	memset(buf, 0x00, sizeof(buf));
	if (hid_init())
		return -1;
	res = hid_init();
	streamdeck = hid_open(0x0fd9, 0x0063, NULL);
	if (!streamdeck)
	{
		hid_exit();
		return -2;
	}
	streamdeck_server();
	
}
