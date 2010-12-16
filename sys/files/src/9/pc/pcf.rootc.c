
#include "u.h"
#include "../port/lib.h"
#include "mem.h"
#include "dat.h"
#include "fns.h"
#include "io.h"
#include "../port/error.h"

extern uchar bootpcf_outcode[];
extern ulong bootpcf_outlen;
extern uchar _386_bin_ip_ipconfigcode[];
extern ulong _386_bin_ip_ipconfiglen;
extern uchar _386_bin_auth_factotumcode[];
extern ulong _386_bin_auth_factotumlen;
extern uchar _386_bin_fossil_fossilcode[];
extern ulong _386_bin_fossil_fossillen;
extern uchar _386_bin_venti_venticode[];
extern ulong _386_bin_venti_ventilen;
extern uchar _386_bin_usb_usbdcode[];
extern ulong _386_bin_usb_usbdlen;

void bootlinks(void){

	addbootfile("boot", bootpcf_outcode, bootpcf_outlen);
	addbootfile("ipconfig", _386_bin_ip_ipconfigcode, _386_bin_ip_ipconfiglen);
	addbootfile("factotum", _386_bin_auth_factotumcode, _386_bin_auth_factotumlen);
	addbootfile("fossil", _386_bin_fossil_fossilcode, _386_bin_fossil_fossillen);
	addbootfile("venti", _386_bin_venti_venticode, _386_bin_venti_ventilen);
	addbootfile("usbd", _386_bin_usb_usbdcode, _386_bin_usb_usbdlen);

}

