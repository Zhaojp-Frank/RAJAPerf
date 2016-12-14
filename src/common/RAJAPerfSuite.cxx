/*!
 ******************************************************************************
 *
 * \file
 *
 * \brief   Implementation file for routines that define performance suite 
            kernels, variants, and run parameters.
 *
 ******************************************************************************
 */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Copyright (c) 2017, Lawrence Livermore National Security, LLC.
//
// Produced at the Lawrence Livermore National Laboratory
//
// LLNL-CODE-xxxxxx
//
// All rights reserved.
//
// This file is part of the RAJA Performance Suite.
//
// For additional details, please read the file LICENSE.
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#include "RAJAPerfSuite.hxx"

#include <cstdlib>
#include <cstdio>

namespace RAJAperf
{

/*
 *******************************************************************************
 *
 * Ctor for PunParams struct defines suite execution defaults.
 *
 *******************************************************************************
 */
RunParams::RunParams(int argc, char** argv)
 : npasses(1),
   run_kernels("all");
   run_variants("all"); 
   length_fraction(1.0); 
   output_file_prefix("RAJA_Perf_Suite");
{
  for (int i = 1; i < argc; ++i) {

    if ( strcmp( argv[i], "--npasses" ) == 0 ) {

      npasses = ::atoi( argv[++i] );

    } else if ( strcmp( argv[i], "--kernels" ) == 0 ) {

      // RDH TODO...

    } else if ( strcmp( argv[i], "--variants" ) == 0 ) {

      // RDH TODO...

    } else if ( strcmp(argv[i], "--lenfrac" ) == 0 ) {

      length_fraction = ::atof( argv[++i] );

    } else if ( strcmp(argv[i], "--outfile" ) == 0 ) {
   
      output_file_prefix = std::string( argv[++i] ); 

    } else if ( strcmp(argv[i], "--help" )==0 ) {

      std::cout << "\n\n";
      std::cout << "Usage: ./raja-perf [options] ";
      std::cout << std::endl;
      std::cout.flush();

  }
}




/*!
 *******************************************************************************
 *
 * \brief Parse input options and sets RunParams struct members.
 *
 *******************************************************************************
 */
void parseInputParams(int argc, char** argv, RunParams& params);

/*!
 *******************************************************************************
 *
 * \brief Return kernel name associated with KernelID enum value.
 *
 *******************************************************************************
 */
std::string getKernelName(KernelID kid);

/*!
 *******************************************************************************
 *
 * \brief Return variant name associated with VariantID enum value.
 *
 *******************************************************************************
 */
std::string getVariantName(VariantID vid);

}  // closing brace for RAJAperf namespace

#endif  // closing endif for header file include guard
