tests = [ {'description': 'Zero',
    'steps': [{'inputs': [('PINA',0x00)], 'iterations': 1 },
              {'inputs': [('PINA',0x00)], 'iterations': 1 },
              {'inputs': [('PINA',0x01)], 'iterations': 1 },
             {'inputs': [('PINA',0x02)], 'iterations': 1 }],
    'expected': [('PORTC',0x00)],
    },
    {'description': 'add',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 1 },
              {'inputs': [('PINA',0x00)], 'iterations': 1 },
              {'inputs': [('PINA',0x01)], 'iterations': 1 },
              {'inputs': [('PINA',0x01)], 'iterations': 1 },
              {'inputs': [('PINA',0x00)], 'iterations': 1 }],
    'expected': [('PORTC',0x08)],
    },
    {'description': 'sub',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 1 },
              {'inputs': [('PINA',0x00)], 'iterations': 1 },
              {'inputs': [('PINA',0x02)], 'iterations': 1 },
              {'inputs': [('PINA',0x02)], 'iterations': 1 },
              {'inputs': [('PINA',0x00)], 'iterations': 1 }],
    'expected': [('PORTC',0x06)],
    },
    ]

watch = ['PORTC']
