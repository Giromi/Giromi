use std::fs;
use std::io;

fn main() -> io::Result<()> {
    // 난이도별로 정리된 파일 이름
    let files = vec![
        // 기초 (000~039)
        "000_comments.rs",
        "001_variables.rs",
        "002_conditions.rs",
        "003_loops.rs",
        "004_functions.rs",
        "005_structs.rs",
        "006_enums.rs",
        "007_vectors.rs",
        "008_error_handling.rs",
        "009_file_io.rs",
        "010_class_basics.rs",
        "011_visibility.rs",
        "012_traits_polymorphism.rs",
        "013_smart_pointers.rs",
        "014_memory_management.rs",
        "015_multithreading_basics.rs",
        "016_trait_objects.rs",
        "017_closure_iter.rs",
        "018_generic_struct.rs",
        "019_closure_sort.rs",
        "020_error_custom.rs",
        "021_static_lifetime.rs",
        "022_static_variable.rs",
        "023_const_variable.rs",
        "024_trait_bound.rs",
        "025_advanced_generics.rs",
        "026_hashmap.rs",
        "027_json_parsing.rs",
        "028_serde_struct.rs",
        "029_todo_macro.rs",
        "030_macro_basics.rs",
        "031_custom_macro.rs",
        "032_recursive_function.rs",
        "033_pattern_matching.rs",
        "034_file_copy.rs",
        "035_regex.rs",
        "036_static_dispatch.rs",
        "037_dynamic_dispatch.rs",
        "038_closure_mut.rs",
        "039_vec2d.rs",
        // 중급 (040~079)
        "040_threadpool.rs",
        "041_parallel_computation.rs",
        "042_async_basic.rs",
        "043_async_file_io.rs",
        "044_http_request.rs",
        "045_multithreading_channel.rs",
        "046_rc_vs_arc.rs",
        "047_advanced_closures.rs",
        "048_advanced_traits.rs",
        "049_dynamic_loading.rs",
        "050_web_server.rs",
        "051_websocket.rs",
        "052_binary_search.rs",
        "053_advanced_lifetimes.rs",
        "054_custom_error_handling.rs",
        "055_tokio_tasks.rs",
        "056_state_pattern.rs",
        "057_serde_json_example.rs",
        "058_trait_object_dispatch.rs",
        "059_dynamic_trait_example.rs",
        "060_arc_mutex_example.rs",
        "061_file_streaming.rs",
        "062_http_client.rs",
        "063_json_serialization.rs",
        "064_file_merging.rs",
        "065_trait_implementation.rs",
        "066_simple_crud.rs",
        "067_basic_wasm.rs",
        "068_simple_gui.rs",
        "069_rust_module.rs",
        "070_external_crate.rs",
        "071_memory_leak_check.rs",
        "072_rust_benchmark.rs",
        "073_async_server.rs",
        "074_mpsc_example.rs",
        "075_worker_thread.rs",
        "076_advanced_generics.rs",
        "077_futures_intro.rs",
        "078_logging_with_env.rs",
        "079_async_web_framework.rs",
        // 고급 (080~100)
        "080_wasm_advanced.rs",
        "081_ffi_example.rs",
        "082_advanced_memory.rs",
        "083_unsafe_rust.rs",
        "084_zero_cost_abstractions.rs",
        "085_tokio_runtime.rs",
        "086_multithreading_advanced.rs",
        "087_web_framework.rs",
        "088_parallel_processing.rs",
        "089_cross_platform.rs",
        "090_cargo_optimizations.rs",
        "091_plugin_architecture.rs",
        "092_rust_wgpu.rs",
        "093_open_gl.rs",
        "094_networking_framework.rs",
        "095_data_pipeline.rs",
        "096_advanced_macros.rs",
        "097_advanced_error.rs",
        "098_async_testing.rs",
        "099_final_project_template.rs",
        "100_project_summary.rs",
    ];

    // 파일 생성
    for file in files {
        let content = match file {
            "000_comments.rs" => format!("// {}\n// 이 파일은 Rust 주석 연습을 위한 파일입니다.\n", file),
            "100_project_summary.rs" => format!("// {}\n// 이 파일은 100개의 Rust 연습 프로젝트를 요약합니다.\n", file),
            _ => format!("// {}\n", file),
        };

        fs::write(file, content)?;
        println!("{} 파일 생성 완료!", file);
    }

    println!("모든 파일 생성 완료!");
    Ok(())
}
