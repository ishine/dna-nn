#ifndef DNAIO_H
#define DNAIO_H

#include <stdint.h>

typedef struct {
	int n, m, n_lbl;
	uint8_t **seq;
	uint8_t **lbl;
	int *len;
	uint64_t *sum_len;
} dn_seqs_t;

typedef struct {
	int len;
	char *name, *seq, *qual;
	uint8_t *lbl;
} dn_bseq1_t;

typedef struct {
	 int m, n;
	 dn_bseq1_t *a;
} dn_bseq_t;

extern unsigned char seq_nt4_table[256];

void dn_seq2vec_ds(int l, const uint8_t *seq4, float *x);
int dn_select_seq(const dn_seqs_t *tr, double r);
dn_seqs_t *dn_read(const char *fn);
void dn_destroy(dn_seqs_t *s);

int dn_bseq_read(void *ks_, dn_bseq_t *bs, int max);
void dn_bseq_reset(dn_bseq_t *bs);

static inline void dn_base2vec(int c, float *x)
{
	int k;
	if (c < 4 && c >= 0) {
		for (k = 0; k < 4; ++k)
			x[k] = 0.0f;
		x[c] = 1.0f;
	} else {
		for (k = 0; k < 4; ++k)
			x[k] = 0.25f;
	}
}

#endif
