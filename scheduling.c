#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <linux/sched.h>
#include <linux/sched/types.h>

int main(void) {
    struct schedule_attr attr = {
        .size = sizeof(struct sched_attr),
        .sched_policy = SCHED_OTHER,
        .sched_nice = 5
    };

    if (syscall(SYS_sched_setattr, 0, &attr, 0) < 0) {
        perror("sched_setattr");
        return 1;
    }

    printf("nice value set to %d\n", attr.sched_nice);
    return 0;
}



