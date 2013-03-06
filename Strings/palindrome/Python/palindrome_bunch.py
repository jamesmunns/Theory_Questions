import argparse

args_setup = argparse.ArgumentParser( description='Palindromic Checker' )

def setup_CLI():
    args_setup.add_argument( 'teststr',  metavar = 'TESTSTR',  type = str, help = 'String Under Test'  )
    return args_setup.parse_args()

def main():
    pal_fns = [ c_style, reverse_style ]

    args = setup_CLI()
    for fn in pal_fns:
        fn( args.teststr )

def c_style( teststr ):
    flag = "Pass"
    for i in xrange( len( teststr ) / 2 ):
        if teststr[ i ] != teststr[ -( i+1 ) ]:
            flag = "Fail"
            break

    print "c_style check: %s" % flag

def reverse_style( teststr ):
    print "reverse_style check: %s" % ( "Pass" if ( teststr == ( teststr[::-1] ) ) else "Fail" )

#Truthfully, I was going to do some stuff with iterators or half string reversing, but the reverse_style really takes the cake.

if __name__ == '__main__':
    main()