tests = [ {'description': 'one cycle',
    'steps': [ {'inputs': [('PINA',0x01)], 'iterations': 1 },
             {'inputs': [('PINA',0x00)], 'iterations': 1 }],
    'expected': [('PORTB',0x02)],
    },
    {'description': '2 cycle',
    'steps': [ {'inputs': [('PINA',0x01)], 'iterations': 1 },
              {'inputs': [('PINA',0x00)], 'iterations': 1 },
                {'inputs': [('PINA',0x02)], 'iterations': 1 },
             {'inputs': [('PINA',0x01)], 'iterations': 1 }],
    'expected': [('PORTB',0x01)],
    },
    ]

watch = ['PORTB']
