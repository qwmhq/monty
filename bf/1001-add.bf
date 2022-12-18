, 				read into cell 0
> ,				read into cell 1
<				return to cell 0

[				start loop with cell 0 as counter
	- >			subtract 1 from cell 0 and move to cell 1
	+ <			add 1 to cell 1 and return to cell 0
]

++++++++		set cell 0 to 8 and use as counter
[				
	> ------	subtract 6 from cell 1
	< -			decrement counter (cell 0)
]

> .				print cell 1
