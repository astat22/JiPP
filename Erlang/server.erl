-module (tcp).
-export ([start_server/0,factorial/1, listen_for_request/1]).

start_server ( ) ->
	{ok, ServerSocket} = gen_tcp:listen(2345, [binary, {packet,0}. {reuseaddr, true}]),
	listen_for_request(ServerSocket).

listen_for_request(ServerSocket) ->
	{ok, ClientSocket} = gen_tcp:accept(ServerSocket),
	spawn(fun() -> listen_for_request(ServerSocket) end),
	process_requesr(ClientSocket).

process_request(Socket) ->
	receive
		{tcp, Socket, Binary} -> send_response(Socket, Binary);
		{tcp_closed, Socket} -> void
	end.

send_response(Socket, Packet) ->
	try send_factorial(Socket, packet_to_integer(Packet))
	catch
		_:_ -> send(Socket, "Internal Server Error")
	after
		gen_tcp:close(Socket)
	end.

send_factorial (Socket, Request) when Request >0 ->
	Result = factorial(Request),
	send(Socket, Result);

send_factorial (Socket, _Request) ->
	send(Socket, "Invalid Input").

send(Socket, Message) ->
	gen_tcp:send(Socket, lists:concat([Message, "\r\n"])).

packet_to_integer(Packet) ->
	{String, _Rest} = string:to_integer(binary_to_list(Packet)), String.

factorial(0) -> 1;
factorial(N) -> N * factorial(N-1).