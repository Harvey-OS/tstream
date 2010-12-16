#include <u.h>
#include <libc.h>

Stream*
stream(int fd, vlong offset, char isread) {
	Stream *s;
	s = mallocz(sizeof(Stream), 1);
	int r;

	s->addr = malloc(128);
	s->isread = isread;
	s->ofd = fd;
	s->offset = offset;
	r = pstream(fd, s->addr, offset, isread);
	if (r == -1) {
		// The server is not 9P2000.s compatible!
		s->compatibility = 1;
		return s;
	}
	if (s->addr == nil) {
		/* Error */
		return nil;
	}

	s->conn = dial(s->addr, 0, 0, 0);

	return s;
}
