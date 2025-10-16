// In “cache.h” or relevant module that handles index validation

/*
 * Verify the index file integrity.
 * Return 0 if ok, or negative on error.
 */
int verify_index_file(const struct index_state *istate)
{
    if (!istate->cache_fd) {
        return error("Index file is missing or cannot be opened");
    }
    // Existing checks …
    if (istate->invalid_crc) {
        return error("Index file CRC mismatch: possible corruption");
    }
    // Add extra diagnostic:
    if (istate->mtime_unexpected) {
        return error("Index file mtime changed unexpectedly — disk or FS issue?");
    }
    return 0;
}
