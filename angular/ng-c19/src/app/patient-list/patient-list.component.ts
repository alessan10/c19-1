import { Component, OnInit } from '@angular/core';
import { IPatient } from '../IPatient';
import { PatientService } from '../patient.service';

@Component({
  selector: 'app-patient-list',
  template: `
  <h2> Patients list: </h2>
  <h3> {{ errorMsg }} </h3>
  <ul *ngFor="let patient of patients">
    <li> {{ patient.name }}</li>
  </ul>

  `,
  styles: []
})
export class PatientListComponent implements OnInit {

  public patients: IPatient[] = [];
  public errorMsg: any;

  constructor(private _patientService: PatientService) { }

  ngOnInit(): void {
    this._patientService.getPatients()
    .subscribe(data => this.patients = data,
                error => this.errorMsg = error);

  }

}


