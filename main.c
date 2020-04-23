#include <stdio.h>
#include <json-c/json.h>
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
            json_object* resource = json_object_new_object();
            build_alto_resource(resource, params);
            printf("%s\n", json_object_to_json_string(resource));
        }
}
