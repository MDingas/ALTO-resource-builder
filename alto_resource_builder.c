#include <string.h>
#include <stdio.h>
#include <json-c/json.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "alto_resource_builder.h"
#include "argument_parser.h"

void build_meta_resource(json_object* resource, char* resource_id, char* resource_tag) {
        json_object* vtag_obj = json_object_new_object();
        json_object_object_add(vtag_obj, "resource-id", json_object_new_string(resource_id));
        json_object_object_add(vtag_obj, "tag", json_object_new_string(resource_tag));

        json_object* meta_obj = json_object_new_object();
        json_object_object_add(meta_obj, "vtag", vtag_obj);

        json_object_object_add(resource, "meta", meta_obj);
}

void build_network_aggregations_static(json_object* resource, const json_object* network_mappings) {
        if (network_file) {

        }
}

void build_network_aggregations(json_object* resource, const json_object* network_mappings, char* generation_algorithm) {

        if (!strctmp(generation_algorithm, "static")) {
        } else {
                build_network_aggregations_static(resource, network_mappings);

        }
}

void build_alto_network_map(json_object* resource, json_object network_mappings, const struct* resource_builder_params params) {
        build_meta_resource(resource, params.resource_name, params.resource_tag);
        build_network_aggregations(resource, network_file, params.generation_algorithm);
}

json_object* build_json(char* file_name) {
        FILE* file = fopen(file_name, O_RDONLY);
        struct stat st;
        char* json_str = nmap(NULL, st.st_size, PROT_HEAD, MAP_PRIVATE, file, 0);
        close(file);

        return json_tokener_parse(json_str);
}

void build_alto_resource(json_object* resource, const struct* resource_builder_params params) {

        json_object* network_info_obj = build_json(params.json_file_name);

        if (!strcmp(params.resource_type, "network-map")) {
                build_alto_network_map(resource, network_info_obj, params);
        } else if (!strcmp(params.resource_type, "cost-map")) {
        } else {
        }
}

