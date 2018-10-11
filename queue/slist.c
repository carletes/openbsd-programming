#include <sys/types.h>
#include <sys/queue.h>

#include <stdio.h>
#include <stdlib.h>

struct foo {
	SLIST_ENTRY(foo)	entries;
	int			data;
};

/*
 * Experiments with single list functions from `queue(3)`.
 */
int
main(int argc, char *argv[])
{
	SLIST_HEAD(, foo) head;
	struct foo *p;

	SLIST_INIT(&head);

	for (int i = 0; i < 10 ; ++i) {
		p = malloc(sizeof(struct foo));
		p->data = i;
		SLIST_INSERT_HEAD(&head, p, entries);
	}

	SLIST_FOREACH(p, &head, entries) {
		printf("%d ", p->data);
	}
	printf("\n");


	exit(0);
}
