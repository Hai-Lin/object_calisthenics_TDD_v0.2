CC = g++
CFLAGS = -g   -I gtest-1.6.0/include mybuild/libgtest.a -lpthread 
PROG =object_calisthenics_hai 
SRCS=jobseekertest.cpp recruiter.cpp Job.cpp JobSeeker.cpp 


all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG)
