note
	description: "SIMPLE_HTTP with its request state open to the tests."
	author: "Larry Rix"

class
	INSPECTABLE_HTTP

inherit
	SIMPLE_HTTP
		export
			{ANY} custom_headers, query_params, interceptors, build_url
		end

create
	make

end
