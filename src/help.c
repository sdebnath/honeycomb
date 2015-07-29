/*
 * Copyright (c) 2015, Shawn Debnath
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>

#include "honeycomb.h"

/*
 * Prints usage information for honeycomb application and exits
 * with caller provided exit code.
 */
void
hc_usage(int code)
{
	fprintf(stderr,
	    "%s is a command line bhyve administration utility.\n"
	    "\n"
	    "Usage: %s <command> {params}\n"
	    "\n"
	    "Commands:\n"
	    "  help        Prints usage infomration\n"
	    "  list        Lists managed VM instances\n"
	    "  build       Build and start managing a VM with honeycomb\n"
	    "  destroy     Destroy a VM instance\n"
	    "  start       Starts a stopped VM instance\n"
	    "  stop        Stops a running VM instance\n"
	    "  restart     Restarts a running VM instance\n"
	    "  startall    Starts all available VM instances\n"
	    "  stopall     Starts all available VM instances\n"
	    "  restartall  Restarts all available VM instances\n"
	    "\n"
	    "To get more information about a specific command, you can specify\n"
	    "the name of the command as the parameter to help:\n"
	    "\n"
	    "  %s help <command>\n"
	    "\n",
	    PROGNAME, PROGBIN, PROGBIN);

	exit(code);
}

/*
 * Prints usage information for list command and exits
 * with caller provided exit code.
 */
void
list_usage(int code)
{
	fprintf(stderr,
	    "Lists all VM instances managed by honeycomb.\n"
	    "\n"
	    "Usage: %s list [-v]\n"
	    "\n"
	    "	-v: Show verbose information about VM instaces\n"
	    "\n",
	    PROGBIN);

	exit(code);
}

/*
 * Prints usage information for build command and exits
 * with caller provided exit code.
 */
void
build_usage(int code)
{
	fprintf(stderr,
	    "Builds and starts managing a VM with honeycomb.\n"
	    "\n"
	    "Usage: %s build [-c config]\n"
	    "\n"
	    "	-c: Full path to the configuration file\n"
	    "\n",
	    PROGBIN);

	exit(code);
}

/*
 * Prints usage information for destroy command and exits
 * with caller provided exit code.
 */
void
destroy_usage(int code)
{
	fprintf(stderr,
	    "Destroys a VM instance managed by honeycomb.\n"
	    "\n"
	    "Usage: %s destroy [-i instance]\n"
	    "\n"
	    "	-i: Name of the VM instance\n"
	    "\n",
	    PROGBIN);

	exit(code);
}

/*
 * Prints usage information for start command and exits
 * with caller provided exit code.
 */
void
start_usage(int code)
{
	fprintf(stderr,
	    "Starts a stopped honeycomb managed VM instance.\n"
	    "\n"
	    "Usage: %s start [-i instance]\n"
	    "\n"
	    "	-i: Name of the VM instance\n"
	    "\n",
	    PROGBIN);

	exit(code);
}

/*
 * Prints usage information for stop command and exits
 * with caller provided exit code.
 */
void
stop_usage(int code)
{
	fprintf(stderr,
	    "Stops a started honeycomb managed VM instance.\n"
	    "\n"
	    "Usage: %s stop [-i instance] [-f]\n"
	    "\n"
	    "	-f: Force stop the VM instance\n"
	    "	-i: Name of the VM instance\n"
	    "\n",
	    PROGBIN);

	exit(code);
}

/*
 * Prints usage information for restart command and exits
 * with caller provided exit code.
 */
void
restart_usage(int code)
{
	fprintf(stderr,
	    "Restarts a started honeycomb managed VM instance.\n"
	    "\n"
	    "Usage: %s restart [-i instance] [-f]\n"
	    "\n"
	    "	-f: Force stop the VM instance before restarting\n"
	    "	-i: Name of the VM instance\n"
	    "\n",
	    PROGBIN);

	exit(code);
}

/*
 * Prints usage information for startall command and exits
 * with caller provided exit code.
 */
void
startall_usage(int code)
{
	fprintf(stderr,
	    "Starts all available VM instances managed by honeycomb.\n"
	    "\n"
	    "Usage: %s startall\n"
	    "\n",
	    PROGBIN);


	exit(code);
}

/*
 * Prints usage information for stopall command and exits
 * with caller provided exit code.
 */
void
stopall_usage(int code)
{
	fprintf(stderr,
	    "Stops all available VM instances managed by honeycomb.\n"
	    "\n"
	    "Usage: %s destroy [-f]\n"
	    "\n"
	    "	-f: Force stop all VM instances\n"
	    "\n",
	    PROGBIN);


	exit(code);
}

/*
 * Prints usage information for restartall command and exits
 * with caller provided exit code.
 */
void
restartall_usage(int code)
{
	fprintf(stderr,
	    "Restarts all VM instances managed by honeycomb.\n"
	    "\n"
	    "Usage: %s restartall [-f]\n"
	    "\n"
	    "	-f: Force stop all VMs prior to restarting\n"
	    "\n",
	    PROGBIN);


	exit(code);
}
