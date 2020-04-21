#include <string.h>
#include <stdio.h>
#include <json-c/json.h>
#include "alto_resource_builder.h"
#include "argument_parser.h"

void build_alto_network_map(struct resource_builder_params params) {

        json_object* resource_name_str_obj = json_object_new_string(params.resource_name);
        json_object* resource_version_str_obj =json_object_new_string(params.resource_tag);


        json_object* vtag_obj = json_object_new_object();
        json_object_object_add(vtag_obj, "resource-id", resource_name_str_obj);
        json_object_object_add(vtag_obj, "tag", resource_name_str_obj);

        json_object* meta_obj = json_object_new_object();
        json_object_object_add(meta_obj, "vtag", vtag_obj);

        json_object* obj = json_object_new_object();
        json_object_object_add(obj, "meta", meta_obj);

        printf("%s\n", json_object_to_json_string(obj));
}

void build_alto_resource(struct resource_builder_params params) {
        if (!strcmp(params.resource_type, "network-map")) {
                build_alto_network_map(params);
        } else if (!strcmp(params.resource_type, "cost-map")) {
                build_alto_network_map(params);

        } else {
        }
}

