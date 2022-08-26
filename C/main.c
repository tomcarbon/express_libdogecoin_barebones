#include <stdio.h>
#include "libdogecoin.h"

#define PRIV_KEY_LENGTH		53
#define ADDRESS_LENGTH		35

int main(int argc, char **argv) {
char wif_privkey[PRIV_KEY_LENGTH+1];
char dogecoin_address[ADDRESS_LENGTH+1];

	dogecoin_ecc_start();

	if (generatePrivPubKeypair(wif_privkey, dogecoin_address, 0)) {
		printf("{\"data\":{\"privkey\":\"%s\",\"pubkey\":\"%s\"}}", wif_privkey, dogecoin_address);
	} else {
		printf("{\"data\":\"error\":\"Failure from generatePrivPubKeypair()\"}}");
	}

	dogecoin_ecc_stop();
return 0;
}
