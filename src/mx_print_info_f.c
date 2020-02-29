#include "uls.h"

static void g_or_l(t_files *files, t_args *args) {
    if (args->fl[4] != 1) {
        mx_printstr(files->entry_file->stat->user_name);
        mx_print_space_file(files->max_user,
                            files->entry_file->stat->user_name);
        mx_printchar(' ');
        mx_printchar(' ');
    }
    if (args->fl[11] != 1) {
        mx_printstr(files->entry_file->stat->group_name);
        mx_print_space_file(files->max_group,
                            files->entry_file->stat->group_name);
        mx_printchar(' ');
        mx_printchar(' ');
    }
    if (args->fl[4] && args->fl[11]) {
        mx_printchar(' ');
        mx_printchar(' ');
    }
}

void mx_print_info_f(t_args *args, t_files *files, t_file_entry *entry_file) {
    mx_printstr(entry_file->stat->permiss);
    mx_printchar(' ');
    mx_print_space_file(files->max_link, entry_file->stat->nlink);
    mx_printstr(entry_file->stat->nlink);
    mx_printchar(' ');
    g_or_l(files, args);
    if (entry_file->stat->permiss[0] == 'b'
       || entry_file->stat->permiss[0] == 'c')
        mx_printstr(entry_file->stat->rdev);
    else {
        if (args->h)
            mx_size_h(entry_file->stat->file_size);
        else {
            mx_print_space_file(files->max_size,
                entry_file->stat->file_size);
            mx_printstr(entry_file->stat->file_size);
        }
    }
}
