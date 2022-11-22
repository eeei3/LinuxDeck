#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <libusb-1.0/libusb.h>
#include <hidapi/hidapi.h>
#define IMAGE_REPORT_LENGTH 8191


typedef struct folder{
	int data;
	struct folder* left;
	struct folder* right;
	unsigned char image[];
} Folder;
typedef struct key{
	int data;
	int command;
	struct folder Folder;
	unsigned char image[];
} Key;

struct streamdeck_keys{
	struct key Key1;
	struct key Key2;
	struct key Key3;
	struct key Key4;
	struct key Key5;
	struct key Key6;
};
hid_device *streamdeck;
int res;
int i;
wchar_t wstr[255];
unsigned char buf[256];
int wait = 1;
char key_pressed[36];
struct streamdeck_keys* root;
struct folder* newFolder(int data)
{}
int command_parser( struct streamdeck_keys key)
{
	return 0;
}
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
					switch (i)
					{
					case 1:
						{}
					case 2:
						{}
					case 3:
						{}
					case 4:
						{}
					case 5:
						{}
					case 6:
						{}
					}
					
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
	struct streamdeck_keys* root;
	streamdeck_server();
	
}
