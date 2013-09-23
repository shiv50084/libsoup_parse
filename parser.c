#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "libsoup/soup-uri.h"

#define SOUP_URI_SCHEME_DVB     _SOUP_ATOMIC_INTERN_STRING (_SOUP_URI_SCHEME_HTTP, "dvb")


int main(int argc, char *argv[])
{
    SoupURI *uri;

    const char in_uri[] = "dvb://0?freq=706000&bandwidth=8&serviceid=1101";


    uri = soup_uri_new(in_uri);

    printf("Scheme: %s\n", soup_uri_get_scheme(uri));
    printf("User: %s\n", soup_uri_get_user(uri));
    printf("Password: %s\n", soup_uri_get_password(uri));
    printf("Host: %s\n", soup_uri_get_host(uri));
    printf("Port: %u\n", soup_uri_get_port(uri));
    printf("Path: %s\n", soup_uri_get_path(uri));

    printf("Query: %s\n", soup_uri_get_query(uri));
    printf("\tQuery String Length: %lu\n", strlen(soup_uri_get_query(uri)));
    char *token, *state;
    char *str = g_malloc0(strlen(soup_uri_get_query(uri))+1);
    strcpy(str, soup_uri_get_query(uri));

    for (token = strtok_r(str, "&", &state);
         token != NULL;
         token = strtok_r(NULL, "&", &state))
    {
        printf("Token: %s [State: %s]\n", token, state);
    }
    g_free(str);

    printf("Fragment: %s\n", soup_uri_get_fragment(uri));

    soup_uri_free(uri);


    return 0;
}
