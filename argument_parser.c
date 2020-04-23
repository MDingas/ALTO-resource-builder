#include <getopt.h>
#include <stdio.h>
#include "argument_parser.h"

int parse_arguments(int argc, char* argv[], struct resource_builder_params* params) {
        int ret = 0;

        /* Set default values */
        params->be_verbose = 0;

        char token;
        int option_index = 0;

        static struct option long_options[] = {
                {"algorithm", required_argument, 0, 'a'},
                {"name",      required_argument, 0, 'n'},
                {"tag",       required_argument, 0, 't'},
                {"verbose",   no_argument,       0, 'v'},
                {0, 0, 0, 0}
        };

        while (ret == 0 && (token = getopt_long(argc, argv, "vn:t:a:", long_options, &option_index)) != -1) {
                switch (token) {
                        case 'a':
                                params->generation_algorithm = optarg;
                                break;
                        case 'n':
                                params->resource_name = optarg;
                                break;
                        case 't':
                                params->resource_tag = optarg;
                                break;
                        case 'v':
                                params->be_verbose = 1;
                                break;
                        case '?':
                                /* getopt_long already printed an error message. */
                                break;
                        default:
                                ret = 1;
                }
        }

        if (argc - optind == ARGUMENT_NUM) {
                params->resource_type = argv[optind];
                params->json_file_name = argv[optind+1];
        } else {
                ret = 1;
                printf("Exactly two arguments needed\n");
        }

        return ret;
}
