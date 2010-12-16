#include <u.h>
#include <libc.h>

int
sclose(Stream *s)
{
	if (!s->compatibility)
		close(s->conn);

	free(s->addr);
	free(s);
	return 0;
}
