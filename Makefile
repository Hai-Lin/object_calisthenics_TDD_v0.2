CC = g++
CFLAGS = -g   -I gtest-1.6.0/include mybuild/libgtest.a -lpthread 
PROG =object_calisthenics_hai 
SRCS=recruitertest.cpp Job.cpp JobSeeker.cpp JobSeekerApplyJob.cpp testhelper.cpp JobSeekerSaveJob.cpp RecruiterPostJob.cpp 


all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG)
