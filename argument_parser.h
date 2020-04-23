#ifndef ALTO_RESOURCE_BUILDER
#define ALTO_RESOURCE_BUILDER

#define ARGUMENT_NUM 2

struct resource_builder_params {
        char* resource_name;
        char* resource_tag;
        char* generation_algorithm;
        int be_verbose;
        char* resource_type;
        char* json_file_name;
};

int parse_arguments(int argc, char* argv[], struct resource_builder_params*);

#endif
