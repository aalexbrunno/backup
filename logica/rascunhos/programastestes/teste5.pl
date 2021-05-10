


apply(turnleft) :-	
	agent_orientation(O),
	New_O is (O + 90) mod 360,
	retractall(agent_orientation(_)),
	assert(agent_orientation(New_O)),
	!.
