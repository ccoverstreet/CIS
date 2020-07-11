// build.zig: Zig build file for CIS
// Cale Overstreet
// June 29, 2020
// Should account for cross-platform compiling as long as the user has the zig executable

const Builder = @import("std").build.Builder;

pub fn build(b: *Builder) void {
    const mode = b.standardReleaseOptions();
    const exe = b.addExecutable("CIS", "src/main.zig");
    exe.setBuildMode(mode);

    exe.install();

    const run_cmd = exe.run();
    const run_step = b.step("run", "Run CIS");
    run_step.dependOn(&run_cmd.step);
}
