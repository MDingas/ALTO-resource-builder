#include <stdio.h>
#include "argument_parser.h"
#include "alto_resource_builder.h"

void usage() {
        printf("usage here\n");
}

int main(int argc, char* argv[]) {
        struct resource_builder_params params;
        if (parse_arguments(argc, argv, &params) != 0 ) {
                usage();
                return 1;
        } else {
            build_alto_resource(params);
        }
}
