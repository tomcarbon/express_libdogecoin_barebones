## express_libdogecoin_barebones

**NOTE**: This program is for **EXAMPLE PURPOSES ONLY**.

## INTRODUCTION 

This project demonstrates a handshake between the libdogecoin library and a Javascript express API, enabling the user to generate libdogecoin-originated privkey/address pairs from (e.g.) any web browser.

To achieve this end, two programs are built:
	1) A Linux executable, written in C.
	2) An express API (nodeJS).

## PREREQUISITES

1) Linux with node/npm installed (also gcc).
2) The libdogecoin library has been built and the libdogecoin.a and libdogecoin.h files have been located.
3) (Optional) Postman program is installed.

## INSTALLATION AND START UP

1) Build the Linux program named qkey:
	a) Copy libdogecoin.a and libdogecoin.h into the C directory.
	b) From a command prompt in the C directory:
		gcc main.c libdogecoin.a -o qkey

2) Build and start up the express server on port 80. From the JS directory:
	a) npm i
	b) [sudo] npm run start

At this point the API should be available at localhost and ready for use.

## HOW TO USE (EXAMPLES)

* From a browser: localhost:/privkey   
* from the linux prompt: curl 127.0.0.1/privkey
* Just use the qkey executable from the linux command prompt with no arguments
* The Postman collection may be used
