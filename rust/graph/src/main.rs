use plotters::prelude::*;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    // 데이터 생성
    let data = vec![(1, 2), (2, 3), (3, 5), (4, 4), (5, 7)];

    // 새로운 그래프 생성
    let root = BitMapBackend::new("plot.png", (640, 480)).into_drawing_area();
    root.fill(&WHITE)?;

    // 새로운 차트 생성
    let mut chart = ChartBuilder::on(&root)
        .caption("Line Plot", ("sans-serif", 40).into_font())
        .build_cartesian_2d(0..6, 0..8)?;

    // 데이터를 선 그래프로 추가
    chart
        .configure_mesh()
        .draw()?;

    chart
        .draw_series(LineSeries::new(data, &RED))?;

    Ok(())
}

