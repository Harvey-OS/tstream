#include <u.h>
#include <libc.h>

long
swrite(Stream *s, void *buf, long len) {
	int n;

	if (s->isread == 0) {
		if (s->compatibility == 0)
			n = pwrite(s->conn, buf, len, -1LL);
		else
			n = pwrite(s->ofd, buf, len, s->offset);

		s->offset += n;
		return n;
	} else {
		return -1;
	}
}