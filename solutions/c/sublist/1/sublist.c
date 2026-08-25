#include "sublist.h"

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count)
{
    size_t count = 0;

    // TEST EQUAL
    if (list_to_compare_element_count == base_list_element_count) {
        for (size_t i = 0; i < base_list_element_count; i++) {
            if (base_list[i] == list_to_compare[i]) {
                count++;
            }
        }

        if (count == base_list_element_count) {
            return EQUAL;
        }
    }

    // SUPERLIST
    // base_list is smaller, so search base_list inside list_to_compare

    if (base_list_element_count == 0 &&
        list_to_compare_element_count > 0) {
        return SUPERLIST;
    }

    if (base_list_element_count < list_to_compare_element_count) {

        for (size_t i = 0;
             i <= list_to_compare_element_count - base_list_element_count;
             i++) {

            int found = 1;

            for (size_t j = 0; j < base_list_element_count; j++) {
                if (list_to_compare[i + j] != base_list[j]) {
                    found = 0;
                    break;
                }
            }

            if (found) {
                return SUPERLIST;
            }
        }
    }

    // SUBLIST
    // list_to_compare is smaller, so search it inside base_list

    if (list_to_compare_element_count == 0 &&
        base_list_element_count > 0) {
        return SUBLIST;
    }

    if (base_list_element_count > list_to_compare_element_count) {

        for (size_t i = 0;
             i <= base_list_element_count - list_to_compare_element_count;
             i++) {

            int found = 1;

            for (size_t j = 0; j < list_to_compare_element_count; j++) {
                if (base_list[i + j] != list_to_compare[j]) {
                    found = 0;
                    break;
                }
            }

            if (found) {
                return SUBLIST;
            }
        }
    }

    return UNEQUAL;
}