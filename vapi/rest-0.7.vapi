/* rest-0.7.vapi generated by vapigen, do not modify. */

[CCode (cprefix = "Rest", gir_namespace = "Rest", gir_version = "0.7", lower_case_cprefix = "rest_")]
namespace Rest {
	[CCode (cheader_filename = "rest/oauth2-proxy.h", cname = "OAuth2Proxy", lower_case_cprefix = "oauth2_proxy_", type_id = "oauth2_proxy_get_type ()")]
	public class OAuth2Proxy : Rest.Proxy {
		[CCode (has_construct_function = false, type = "RestProxy*")]
		public OAuth2Proxy (string client_id, string auth_endpoint, string url_format, bool binding_required);
		public string build_login_url (string redirect_uri);
		public string build_login_url_full (string redirect_uri, GLib.HashTable<void*,void*> extra_params);
		public static string extract_access_token (string url);
		public unowned string get_access_token ();
		public void set_access_token (string access_token);
		[CCode (has_construct_function = false, type = "RestProxy*")]
		public OAuth2Proxy.with_token (string client_id, string access_token, string auth_endpoint, string url_format, bool binding_required);
		public string access_token { get; set; }
		[NoAccessorMethod]
		public string auth_endpoint { owned get; construct; }
		[NoAccessorMethod]
		public string client_id { owned get; construct; }
	}
	[CCode (cheader_filename = "rest/oauth2-proxy-call.h", cname = "OAuth2ProxyCall", lower_case_cprefix = "oauth2_proxy_call_", type_id = "oauth2_proxy_call_get_type ()")]
	public class OAuth2ProxyCall : Rest.ProxyCall {
		[CCode (has_construct_function = false)]
		protected OAuth2ProxyCall ();
	}
	[CCode (cheader_filename = "rest/oauth-proxy.h", cname = "OAuthProxy", lower_case_cprefix = "oauth_proxy_", type_id = "oauth_proxy_get_type ()")]
	public class OAuthProxy : Rest.Proxy {
		[CCode (has_construct_function = false, type = "RestProxy*")]
		public OAuthProxy (string consumer_key, string consumer_secret, string url_format, bool binding_required);
		public bool access_token (string function, string verifier) throws GLib.Error;
		public bool access_token_async (string function, string verifier, [CCode (delegate_target_pos = 4.1, scope = "async")] Rest.OAuthProxyAuthCallback callback, GLib.Object weak_object) throws GLib.Error;
		public bool auth_step (string function) throws GLib.Error;
		public bool auth_step_async (string function, [CCode (delegate_target_pos = 3.1, scope = "async")] Rest.OAuthProxyAuthCallback callback, GLib.Object weak_object) throws GLib.Error;
		public unowned string get_signature_host ();
		public unowned string get_token ();
		public unowned string get_token_secret ();
		public bool is_oauth10a ();
		public Rest.Proxy new_echo_proxy (string service_url, string url_format, bool binding_required);
		public bool request_token (string function, string callback_uri) throws GLib.Error;
		public bool request_token_async (string function, string callback_uri, [CCode (delegate_target_pos = 4.1, scope = "async")] Rest.OAuthProxyAuthCallback callback, GLib.Object weak_object) throws GLib.Error;
		public void set_signature_host (string signature_host);
		public void set_token (string token);
		public void set_token_secret (string token_secret);
		[CCode (has_construct_function = false, type = "RestProxy*")]
		public OAuthProxy.with_token (string consumer_key, string consumer_secret, string token, string token_secret, string url_format, bool binding_required);
		[NoAccessorMethod]
		public string consumer_key { owned get; construct; }
		[NoAccessorMethod]
		public string consumer_secret { owned get; construct; }
		public string signature_host { get; set; }
		[NoAccessorMethod]
		public Rest.OAuthSignatureMethod signature_method { get; set; }
		public string token { get; set; }
		public string token_secret { get; set; }
	}
	[CCode (cheader_filename = "rest/oauth-proxy-call.h", cname = "OAuthProxyCall", lower_case_cprefix = "oauth_proxy_call_", type_id = "oauth_proxy_call_get_type ()")]
	public class OAuthProxyCall : Rest.ProxyCall {
		[CCode (has_construct_function = false)]
		protected OAuthProxyCall ();
		public void parse_token_reponse ();
		public void parse_token_response ();
	}
	[CCode (cheader_filename = "rest/rest-param.h", ref_function = "rest_param_ref", type_id = "rest_param_get_type ()", unref_function = "rest_param_unref")]
	[Compact]
	public class Param {
		[CCode (has_construct_function = false)]
		public Param.full (global::string name, Rest.MemoryUse use, [CCode (array_length_cname = "length", array_length_pos = 3.5, array_length_type = "gsize")] uint8[] data, global::string content_type, global::string filename);
		public void* get_content ();
		public size_t get_content_length ();
		public unowned global::string get_content_type ();
		public unowned global::string get_file_name ();
		public unowned global::string get_name ();
		public bool is_string ();
		public unowned Rest.Param @ref ();
		[CCode (has_construct_function = false)]
		public Param.string (global::string name, Rest.MemoryUse use, global::string string);
		public void unref ();
		[CCode (has_construct_function = false)]
		public Param.with_owner (global::string name, [CCode (array_length_cname = "length", array_length_pos = 2.5, array_length_type = "gsize")] uint8[] data, global::string content_type, global::string? filename, owned void* owner, GLib.DestroyNotify? owner_dnotify);
	}
	[CCode (cheader_filename = "rest/rest-params.h", has_type_id = false)]
	[Compact]
	public class Params {
		public void add (owned Rest.Param param);
		public bool are_strings ();
		public GLib.HashTable<weak string,weak string> as_string_hash_table ();
		public void free ();
		public unowned Rest.Param? @get (string name);
		public void remove (string name);
	}
	[CCode (cheader_filename = "rest/rest-params.h", has_type_id = false)]
	[Compact]
	public class ParamsIter {
		public void init (Rest.Params @params);
		public bool next (out unowned string name, out unowned Rest.Param? param);
	}
	[CCode (cheader_filename = "rest/rest-proxy.h", type_id = "rest_proxy_get_type ()")]
	public class Proxy : GLib.Object {
		[CCode (has_construct_function = false)]
		public Proxy (string url_format, bool binding_required);
		[Version (since = "0.7.92")]
		public void add_soup_feature (Soup.SessionFeature feature);
		public bool bind (...);
		public unowned string get_user_agent ();
		public virtual Rest.ProxyCall new_call ();
		public void set_user_agent (string user_agent);
		[CCode (has_construct_function = false)]
		public Proxy.with_authentication (string url_format, bool binding_required, string username, string password);
		[NoAccessorMethod]
		public bool binding_required { get; set; }
		[NoAccessorMethod]
		public bool disable_cookies { get; construct; }
		[NoAccessorMethod]
		public string password { owned get; set; }
		[NoAccessorMethod]
		public string ssl_ca_file { owned get; set; }
		[NoAccessorMethod]
		public bool ssl_strict { get; set; }
		[NoAccessorMethod]
		public string url_format { owned get; set; }
		public string user_agent { get; set; }
		[NoAccessorMethod]
		public string username { owned get; set; }
		public virtual signal bool authenticate (Rest.ProxyAuth auth, bool retrying);
	}
	[CCode (cheader_filename = "rest/oauth-proxy-call.h,rest/oauth-proxy.h,rest/oauth2-proxy-call.h,rest/oauth2-proxy.h,rest/rest-enum-types.h,rest/rest-param.h,rest/rest-params.h,rest/rest-proxy-auth.h,rest/rest-proxy-call.h,rest/rest-proxy.h,rest/rest-xml-node.h,rest/rest-xml-parser.h", type_id = "rest_proxy_auth_get_type ()")]
	public class ProxyAuth : GLib.Object {
		[CCode (has_construct_function = false)]
		protected ProxyAuth ();
		public void cancel ();
		public void pause ();
		public void unpause ();
	}
	[CCode (cheader_filename = "rest/rest-proxy-call.h", type_id = "rest_proxy_call_get_type ()")]
	public class ProxyCall : GLib.Object {
		[CCode (has_construct_function = false)]
		protected ProxyCall ();
		public void add_header (string header, string value);
		public void add_headers (...);
		public void add_param (string name, string value);
		public void add_param_full (owned Rest.Param param);
		public void add_params (...);
		public bool cancel ();
		public bool continuous ([CCode (delegate_target_pos = 2.1)] Rest.ProxyCallContinuousCallback callback, GLib.Object weak_object) throws GLib.Error;
		[Version (since = "0.7.92")]
		public unowned string get_function ();
		public unowned string get_method ();
		public unowned Rest.Params get_params ();
		public unowned string get_payload ();
		public int64 get_payload_length ();
		public GLib.HashTable<weak string,weak string> get_response_headers ();
		public uint get_status_code ();
		public unowned string get_status_message ();
		public async bool invoke_async (GLib.Cancellable? cancellable) throws GLib.Error;
		public unowned string lookup_header (string header);
		public Rest.Param lookup_param (string name);
		public unowned string lookup_response_header (string header);
		[NoWrapper]
		public virtual bool prepare () throws GLib.Error;
		public void remove_header (string header);
		public void remove_param (string name);
		public bool run (out unowned GLib.MainLoop loop = null) throws GLib.Error;
		[CCode (cname = "rest_proxy_call_async")]
		public bool run_async ([CCode (delegate_target_pos = 2.1)] Rest.ProxyCallAsyncCallback callback, GLib.Object? weak_object = null) throws GLib.Error;
		public virtual bool serialize_params (out string content_type, out string content, out size_t content_len) throws GLib.Error;
		public void set_function (string function);
		public void set_method (string method);
		public bool sync () throws GLib.Error;
		public bool upload ([CCode (delegate_target_pos = 2.1, scope = "async")] Rest.ProxyCallUploadCallback callback, GLib.Object weak_object) throws GLib.Error;
		[NoAccessorMethod]
		public Rest.Proxy proxy { owned get; construct; }
	}
	[CCode (cheader_filename = "rest/rest-xml-node.h", ref_function = "rest_xml_node_ref", type_id = "rest_xml_node_get_type ()", unref_function = "rest_xml_node_unref")]
	[Compact]
	public class XmlNode {
		public weak GLib.HashTable<void*,void*> attrs;
		public weak GLib.HashTable<void*,void*> children;
		public weak string content;
		public weak string name;
		public weak Rest.XmlNode next;
		public void add_attr (string attribute, string value);
		public unowned Rest.XmlNode add_child (string tag);
		public Rest.XmlNode find (string tag);
		public void free ();
		public unowned string get_attr (string attr_name);
		public string print ();
		public unowned Rest.XmlNode @ref ();
		public void set_content (string value);
		public void unref ();
	}
	[CCode (cheader_filename = "rest/rest-xml-parser.h", type_id = "rest_xml_parser_get_type ()")]
	public class XmlParser : GLib.Object {
		[CCode (has_construct_function = false)]
		public XmlParser ();
		public Rest.XmlNode parse_from_data (string data, int64 len);
	}
	[CCode (cheader_filename = "rest/rest-param.h", cprefix = "REST_MEMORY_", has_type_id = false)]
	public enum MemoryUse {
		STATIC,
		TAKE,
		COPY
	}
	[CCode (cheader_filename = "rest/oauth-proxy.h", cname = "OAuthSignatureMethod", cprefix = "", type_id = "oauth_signature_method_get_type ()")]
	public enum OAuthSignatureMethod {
		PLAINTEXT,
		HMAC_SHA1
	}
	[CCode (cheader_filename = "rest/rest-proxy-call.h", cprefix = "REST_PROXY_CALL_")]
	public errordomain ProxyCallError {
		FAILED;
		public static GLib.Quark quark ();
	}
	[CCode (cheader_filename = "rest/rest-proxy.h", cprefix = "REST_PROXY_ERROR_")]
	public errordomain ProxyError {
		CANCELLED,
		RESOLUTION,
		CONNECTION,
		SSL,
		IO,
		FAILED,
		HTTP_MULTIPLE_CHOICES,
		HTTP_MOVED_PERMANENTLY,
		HTTP_FOUND,
		HTTP_SEE_OTHER,
		HTTP_NOT_MODIFIED,
		HTTP_USE_PROXY,
		HTTP_THREEOHSIX,
		HTTP_TEMPORARY_REDIRECT,
		HTTP_BAD_REQUEST,
		HTTP_UNAUTHORIZED,
		HTTP_FOUROHTWO,
		HTTP_FORBIDDEN,
		HTTP_NOT_FOUND,
		HTTP_METHOD_NOT_ALLOWED,
		HTTP_NOT_ACCEPTABLE,
		HTTP_PROXY_AUTHENTICATION_REQUIRED,
		HTTP_REQUEST_TIMEOUT,
		HTTP_CONFLICT,
		HTTP_GONE,
		HTTP_LENGTH_REQUIRED,
		HTTP_PRECONDITION_FAILED,
		HTTP_REQUEST_ENTITY_TOO_LARGE,
		HTTP_REQUEST_URI_TOO_LONG,
		HTTP_UNSUPPORTED_MEDIA_TYPE,
		HTTP_REQUESTED_RANGE_NOT_SATISFIABLE,
		HTTP_EXPECTATION_FAILED,
		HTTP_INTERNAL_SERVER_ERROR,
		HTTP_NOT_IMPLEMENTED,
		HTTP_BAD_GATEWAY,
		HTTP_SERVICE_UNAVAILABLE,
		HTTP_GATEWAY_TIMEOUT,
		HTTP_HTTP_VERSION_NOT_SUPPORTED;
		public static GLib.Quark quark ();
	}
	[CCode (cheader_filename = "rest/oauth-proxy.h", cname = "OAuthProxyAuthCallback", instance_pos = 3.9)]
	public delegate void OAuthProxyAuthCallback (Rest.OAuthProxy proxy, GLib.Error? error, GLib.Object? weak_object);
	[CCode (cheader_filename = "rest/rest-proxy-call.h", instance_pos = 3.9)]
	public delegate void ProxyCallAsyncCallback (Rest.ProxyCall call, GLib.Error? error, GLib.Object? weak_object);
	[CCode (cheader_filename = "rest/rest-proxy-call.h", instance_pos = 5.9)]
	public delegate void ProxyCallContinuousCallback (Rest.ProxyCall call, string buf, size_t len, GLib.Error? error, GLib.Object? weak_object);
	[CCode (cheader_filename = "rest/rest-proxy-call.h", instance_pos = 5.9)]
	public delegate void ProxyCallUploadCallback (Rest.ProxyCall call, size_t total, size_t uploaded, GLib.Error? error, GLib.Object? weak_object);
	[CCode (cheader_filename = "rest/oauth-proxy-call.h,rest/oauth-proxy.h,rest/oauth2-proxy-call.h,rest/oauth2-proxy.h,rest/rest-enum-types.h,rest/rest-param.h,rest/rest-params.h,rest/rest-proxy-auth.h,rest/rest-proxy-call.h,rest/rest-proxy.h,rest/rest-xml-node.h,rest/rest-xml-parser.h")]
	[Version (replacement = "ProxyCallError.quark")]
	public static GLib.Quark proxy_call_error_quark ();
	[CCode (cheader_filename = "rest/oauth-proxy-call.h,rest/oauth-proxy.h,rest/oauth2-proxy-call.h,rest/oauth2-proxy.h,rest/rest-enum-types.h,rest/rest-param.h,rest/rest-params.h,rest/rest-proxy-auth.h,rest/rest-proxy-call.h,rest/rest-proxy.h,rest/rest-xml-node.h,rest/rest-xml-parser.h")]
	[Version (replacement = "ProxyError.quark")]
	public static GLib.Quark proxy_error_quark ();
}
