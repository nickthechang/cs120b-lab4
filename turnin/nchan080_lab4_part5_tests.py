tests = [ {'description': 'right',
    'steps': [{'inputs': [('PINA',0x00)], 'iterations': 1 }, 
              {'inputs': [('PINA',0x03)], 'iterations': 1 },
              {'inputs': [('PINA',0x00)], 'iterations': 1 }, 
              {'inputs': [('PINA',0x01)], 'iterations': 1 }],
    'expected': [('PORTB',0x01)],
    },
    {'description': 'wrong',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 1 },
               {'inputs': [('PINA',0x03)], 'iterations': 1 },
               {'inputs': [('PINA',0x00)], 'iterations': 1 }, 
               {'inputs': [('PINA',0x01)], 'iterations': 1 }],
    'expected': [('PORTB',0x00)],
    },
    ]

watch = ['PORTB']
