#!/bin/bash

# =============================================================================
# test_runner.sh
#
# An enhanced test automation script for the SocialNetwork project.
#
# This script runs the SocialNetwork executable against a predefined test
# suite. It features formatted output for readability, pre-flight checks to
# ensure the environment is ready, and organizes all generated files and
# logs into a dedicated output directory.
#
# Usage:
#   ./test_runner.sh
#
# Make sure this script is executable:
#   chmod +x test_runner.sh
# =============================================================================

# --- Configuration ---
# Paths
EXECUTABLE="./bin/SocialNetwork"
DATA_DIR="./data"
OUT_DIR="./out"

# --- Test Cases ---
# Define the input files and the start vertex to use for each one.
INPUT_FILES=(
    "GRAPH5.TXT"
    "GRAPH10.TXT"
    "GRAPH20.TXT"
)

# IMPORTANT: Update these vertices to be valid for the data files.
START_VERTICES=(
    "A"
    "A"
    "A"
)


# --- Formatting Functions ---

print_separator() {
    printf "%$(tput cols)s\n" "" | tr ' ' '─'
}

print_centered() {
    local text="$1"
    printf "%*s\n" $(( (${#text} + $(tput cols)) / 2 )) "$text"
}


# --- Test Execution Function ---
# run_test(input_filename, start_vertex)
#   - Executes a single test case.
#   - Moves the generated files to the output directory.
run_test() {
    local input_file_path="$1"
    local start_vertex="$2"
    local base_name
    base_name=$(basename "$input_file_path" .TXT)

    print_centered "--- Test Case: $base_name ---"
    print_separator
    echo "  > Input File:   $input_file_path"
    echo "  > Start Vertex: '$start_vertex'"
    echo

    # Check if the input file actually exists
    if [ ! -f "$input_file_path" ]; then
        echo "  > STATUS: FAILED (Input file not found)"
        print_separator
        echo
        return 1
    fi

    echo "  > Executing program..."
    printf "%s\n%s\n" "$input_file_path" "$start_vertex" | $EXECUTABLE > "$OUT_DIR/${base_name}_run.log"

    echo "  > Moving generated files to $OUT_DIR/"
    mv ./${base_name}-*.TXT "$OUT_DIR/" 2>/dev/null

    if [ $? -eq 0 ]; then
        echo "  > STATUS: SUCCESS"
    else
        echo "  > STATUS: WARNING (No output files were found for $base_name)"
        echo "    Check the log for errors: $OUT_DIR/${base_name}_run.log"
    fi

    print_separator
    echo
}


# =============================================================================
# --- Main Script Execution ---
# =============================================================================

# 1. Checks
print_centered "SocialNetwork Test Runner"
print_separator
print_centered "--- 1. Pre-flight Checks ---"

if [ ! -f "$EXECUTABLE" ]; then
    echo "  > ERROR: Executable not found at '$EXECUTABLE'"
    echo "    Please compile the project first (e.g., run 'make')."
    exit 1
fi
echo "  > Executable found: $EXECUTABLE"

if [ ! -d "$DATA_DIR" ]; then
    echo "  > ERROR: Data directory not found at '$DATA_DIR'"
    exit 1
fi
echo "  > Data directory found: $DATA_DIR"
echo
print_separator
echo

# 2. Setup Test Environment
print_centered "--- 2. Setting Up Environment ---"

if [ -d "$OUT_DIR" ]; then
    echo "  > Clearing existing output directory: $OUT_DIR/"
    rm -f "$OUT_DIR"/*
else
    echo "  > Creating new output directory: $OUT_DIR/"
    mkdir -p "$OUT_DIR"
fi
echo "  > Environment is ready."
echo
print_separator
echo

print_centered "--- 3. Starting Test Execution ---"
echo
for i in "${!INPUT_FILES[@]}"; do
    input_filename="${INPUT_FILES[$i]}"
    start_vtx="${START_VERTICES[$i]}"
    run_test "$DATA_DIR/$input_filename" "$start_vtx"
    # sleep 1
done

print_centered "--- All Tests Complete ---"
print_separator
echo "  > All configured test cases have been executed."
echo "  > Check the '$OUT_DIR' directory for the generated output files and run logs."
print_separator
