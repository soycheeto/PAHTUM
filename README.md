# PAHTUM
An ancient Assyrian board game played by a computer

Players-User Story #1
• As a Player, we need to develop a routine playMove which will play the next possible valid move for the Tournament Orchestrator to call in order for for Player to participate in the tournament
• Acceptance Criteria
    • Players are defined as playing either 'X' or 'O'. Cells that are blank shall be denoted by ''. Board size is 7 x 7.
    • playMove shall take inputs as the current board and the player that needs to play ('X' or ''O) and return a valid x, y coordinate for the cell where the move is to be made
    • Players shall define all unit tests to cover basic validation of the function
    • The program needs to have a test suite for playing the game (ideally test it by playing against itself)
    • Routines initializeBoard and printBoard the Board shall be dependent on the (Tournament Orchestrator User Story #1) and (Presentation (UI) - User Story #1) teams
    • Routine printScores shall be dependent on (Presentation(UI) - User Story #2)