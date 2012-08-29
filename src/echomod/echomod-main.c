
#include <stdio.h>
#include <string.h>

static ngx_int_t ngx_echomod_handler(ngx_http_request_t * r) {
    ngx_chain_t out;
    ngx_buf_t * buf;
    char content[32];
    const char * content_type = "text/html";

    strcpy(content, "<h2>Echomod preved</h2>");

    buf = ngx_pcalloc(r->pool, sizeof(ngx_buf_t));
    r->headers_out.status = NGX_HTTP_OK;
    r->headers_out.content_length_n = strlen(content);
    r->headers_out.content_type.len = strlen(content_type);
    r->headers_out.content_type.data = (u_char *) content_type;

    out.buf = buf;
    out.next = NULL;
    return ngx_http_output_filter(r, &out);
}

// incomplete
