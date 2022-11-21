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

struct folder{
	int data;
	struct folder* left;
	struct folder* right;
	unsigned char image[];
};
struct key{
	int data;
	int command;
	unsigned char image[];
};

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
			for (int i = 1; i < res; i++)
			{
				if (buf[i] == 01)
				{
					;
				}

			}

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
