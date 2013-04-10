#ifndef TESTHELPER
#define TESTHELPER

#include "utility.h"
#include "Resume.h"
#include "RecruiterPostJob.h"
#include "SavedJob.h"
#include "jobapplication.h"
#include "SavedJobsManager.h"
#include "JobApplicationsManager.h"

Job* createATSJob();
Job* createJReqJob();
JobSeeker* createJobSeekerWithResume();
JobSeeker* createJobSeekerWithoutResume();
#endif
