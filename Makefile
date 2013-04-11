CC = g++
CFLAGS = -g   -I gtest-1.6.0/include mybuild/libgtest.a -lpthread 
PROG =object_calisthenics_hai 
SRCS= main.cpp Job.cpp JobSeeker.cpp testhelper.cpp jobtest.cpp jobseekertest.cpp recruitertest.cpp SavedJob.cpp Resume.cpp jobapplicationtest.cpp JobApplication.cpp SavedJobsManager.cpp JobApplicationsManager.cpp JobsManager.cpp JobApplicatorInfo.cpp JobApplicationInfo.cpp 


all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG)
