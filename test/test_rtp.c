#include "rtp/kms-rtp-endpoint.h"
#include <glib.h>

#define LOCALNAME "kms/rtp/1"

static KmsEndpoint*
create_endpoint() {
	KmsEndpoint *ep;
	gchar *name;

	name = g_strdup_printf(LOCALNAME);

	ep = g_object_new(KMS_TYPE_RTP_ENDPOINT, "localname", name, NULL);

	g_free(name);
	return ep;
}

static void
check_endpoint(KmsEndpoint *ep) {
	gchar *name;

	g_object_get(ep, "localname", &name, NULL);

	g_assert(g_strcmp0(name, LOCALNAME) == 0);

	g_free(name);
}

gint
main(gint argc, gchar **argv) {
	KmsEndpoint *ep;
	KmsConnection *conn;

	g_type_init();

	ep = create_endpoint();
	check_endpoint(ep);

	conn = kms_endpoint_create_connection(ep, KMS_CONNECTION_TYPE_RTP,
									NULL);
	kms_endpoint_delete_connection(ep, conn, NULL);
	g_object_unref(conn);

	check_endpoint(ep);

	g_object_unref(ep);

	return 0;
}
