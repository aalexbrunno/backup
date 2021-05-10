apontar([WX, WY],turnleft) :-
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 90,
    !.
apontar([WX, WY],turnright) :-
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 270,
    !.
apontar([WX, WY],turnleft) :-
    agent_orientation(O),
    O =:= 180,
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 270,
    !.
apontar([WX, WY],turnright) :-
    agent_orientation(O),
    O =:= 180,
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 90,
    !.
apontar([WX, WY],turnleft) :-
    agent_orientation(O),
    O =:= 90,
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 180,
    !.
apontar([WX, WY],turnright) :-
    agent_orientation(O),
    O =:= 90,
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 0,
    !.
apontar([WX, WY],turnleft) :-
    agent_orientation(O),
    O =:= 270,
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 0,
    !.
apontar([WX, WY],turnright) :-
    agent_orientation(O),
    O =:= 270,
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 180,
    !.
apontar([WX, WY],shoot) :-
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    agent_orientation(O),
    Dir =:=  O,
    !.
