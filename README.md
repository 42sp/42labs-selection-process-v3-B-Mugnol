# 42 Labs 3rd Edition

## Challenge

This is the technical challenge for **42 Labs 3rd Edition**'s selection process. It constitutes of creating a web monitoring tool using C.

## Requirements

This program was created and tested in an UNIX environment with default C libs, clang compiler and libcurl installed. Its capacity to compile and run in other enviroments is completely untested.

## Usage

### _Compiling_

Simply clone this repository and run `make` in its root directory.

```
git clone https://github.com/42sp/42labs-selection-process-v3-B-Mugnol.git Labs_B-Mugnol
cd Labs_B-Mugnol
make
```

### _Input setup_

The services to be monitored must have their information stored in a file named `monitoring.db` (_defined in `inc/define.h` as `I_FILE`_) in the root of the cloned repository, following the format examplified below. Each service configuration must be in its own line; fields are separated by any quantity of `TAB`'s [`'\t'`]. Commentaries (_lines **beginning** with `#`_) and empty lines are ignored.

Protocols are limited to HTTP, PING and DNS.

```bash
# monitoring.db

# HTTP services:
# name		protocol	address			HTTP protocol	expected HTTP code	interval
intra 42	HTTP		intra.42.fr		GET				301					30

# PING services:
# name		protocol	address				interval
game ping	PING		game.42sp.org.br	15

# DNS services:
# name		protocol	address					interval
workspaces	DNS			workspaces.42sp.org.br	60
```

Most fields are self-explanatory. The `interval` fields indicates how often, in seconds, a service will be monitored and generate a new output.

You can have multiple services of diverse protocols written to `monitoring.db` in any order, as long as each configuration line respects its protocol's field formatting.

**Note: for now, only HTTP services using the HEAD protocol work as expected**

### _Executing_

Execute the program generated in the *Compiling* step. It's called *monitoring* by default (_`NAME` variable in *Makefile*_).

```
./monitoring
```

It also accepts the flag *--simplify*, although its usage is yet to be implemented.

### _Output_

For now, the program appends the result of HTTP HEAD requests to the `monitoring.log` file (_defined in `inc/define.h` as `O_FILE`_). A maximum of _`MAX_DATA_FETCHS`_ (_defined in `inc/protocol.h`_) results are written per service correctly specified in `monitoring.db`.
