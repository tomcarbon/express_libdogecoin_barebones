#include "libdogecoin.h"
#include <stdio.h>
#include <string.h>

#define PRIV_KEY_LENGTH		53
#define ADDRESS_LENGTH		35
char wif_privkey[PRIV_KEY_LENGTH+1];
char p2pkh_pubkey[ADDRESS_LENGTH+1];

int main(int argc, char **argv) {
	dogecoin_ecc_start();

	if (generatePrivPubKeypair(wif_privkey, p2pkh_pubkey, 0)) {
		printf("{\"data\":{\"privkey\":\"%s\",\"pubkey\":\"%s\"}}", wif_privkey, p2pkh_pubkey);
	} else {
		printf("{\"data\":\"error\":\"Failure from generatePrivPubKeypair()\"}}");
	}

	dogecoin_ecc_stop();
return 0;
}
