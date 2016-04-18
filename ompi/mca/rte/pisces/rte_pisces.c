/*  I bet this eeds to go  */
#define _GNU_SOURCE
#include <stdio.h>
#include "rte_pisces.h"

int ompi_rte_compare_name_fields(ompi_rte_cmp_bitmask_t mask, const ompi_process_name_t *name1, const ompi_process_name_t *name2) {
	printf("%s: %x %s %s\n", __func__, mask, name1, name2);
	return strcmp(name1,name2);
}

int OMPI_NAME_PRINT(ompi_process_name_t *name) {
	printf("%s: %s\n", __func__, name);
	return 1;
}

int OMPI_CONSTRUCT_JOBID(int family, int job)
{
	printf("%s: %d %d\n", __func__, family, job);
	return family&(0xffff0000)|job&(0xffff);
}

int OMPI_ERROR_LOG(int err)
{
	printf("%s: %d\n", __func__, err);
}

int ompi_rte_abort_peers(ompi_process_name_t *proc, int nprocs, int err)
{
	printf("%s: vpid %d jobid %d %d %d\n", __func__, proc->vpid, proc->jobid, nprocs, err);
	return 1;
}

int OMPI_LOCAL_JOBID(int job)
{
	printf("%s: %d\n", __func__, job);
	return 1;
}

int OMPI_JOB_FAMILY(int job)
{
	printf("%s: %d\n", __func__, job);
	return 1;
}

int ompi_rte_convert_string_to_process_name(ompi_process_name_t *name, const char *str)
{
	printf("%s: vpid %d jobid %d %s\n", __func__, name->vpid, name->jobid, str);
	name->vpid = 1;
	name->jobid = 1;
	printf("%s: vpid %d jobid %d %s\n", __func__, name->vpid, name->jobid, str);
	return 1;
}

int ompi_rte_convert_process_name_to_string(char **str,  const ompi_process_name_t *name)
{
	printf("%s: vpid %d jobid %d %p\n", __func__, name->vpid, name->jobid, *str);
	return asprintf(*str, "%d.%d", __func__, name->vpid, name->jobid, str);
}

int ompi_rte_init(int *argc, char ***argv)
{
	int i;

	printf("%s: *argc %d", __func__, argc);
	for(i = 0; i < *argc; i++) {
		printf(" %s", *argv[i]);
	}
	printf("\n");
	return 1;
}

int ompi_rte_finalize(void)
{
	printf("%s:\n", __func__);
	return 1;
}
