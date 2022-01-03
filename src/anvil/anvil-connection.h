#ifndef ANVIL_CONNECTION_H
#define ANVIL_CONNECTION_H

/* Error is set and reply=NULL on internal errors. */
typedef void
anvil_connection_cmd_callback_t(const char *reply, const char *error,
				void *context);

void anvil_connection_create(int fd, bool master, bool fifo);

/* Find an existing anvil connection from the specified process. */
struct anvil_connection *anvil_connection_find(const char *service, pid_t pid);

void anvil_connection_send_cmd(struct anvil_connection *conn,
			       const char *cmdline,
			       anvil_connection_cmd_callback_t *callback,
			       void *context);

void anvil_connections_init(void);
void anvil_connections_deinit(void);

#endif
