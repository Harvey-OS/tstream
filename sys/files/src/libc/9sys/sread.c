#include <u.h>
#include <libc.h>

long
sread(Stream *s, void *buf, long len) {
	int n;

	if (s->isread == 1) {
		if (s->compatibility == 0)
			n = pread(s->conn, buf, len, -1LL);
		else
			n = pread(s->ofd, buf, len, s->offset);

		s->offset += n;
		return n;
	} else {
		return -1;
	}
}
